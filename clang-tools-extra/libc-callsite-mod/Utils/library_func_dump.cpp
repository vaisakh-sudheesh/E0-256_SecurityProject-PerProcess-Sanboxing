#include <iostream>
#include <fstream>
#include <libelf.h>
#include <fcntl.h>
#include <gelf.h>
#include <unistd.h>

void extractFunctionNames(const char *libPath, const char *outputFile) {
    if (elf_version(EV_CURRENT) == EV_NONE) {
        std::cerr << "ELF library initialization failed: " << elf_errmsg(-1) << std::endl;
        return;
    }

    int fd = open(libPath, O_RDONLY, 0);
    if (fd < 0) {
        std::cerr << "Failed to open file: " << libPath << std::endl;
        return;
    }

    Elf *elf = elf_begin(fd, ELF_C_READ, nullptr);
    if (!elf) {
        std::cerr << "elf_begin() failed: " << elf_errmsg(-1) << std::endl;
        close(fd);
        return;
    }

    Elf_Scn *scn = nullptr;
    GElf_Shdr shdr;
    while ((scn = elf_nextscn(elf, scn)) != nullptr) {
        gelf_getshdr(scn, &shdr);
        if (shdr.sh_type == SHT_SYMTAB || shdr.sh_type == SHT_DYNSYM) {
            break;
        }
    }

    if (!scn) {
        std::cerr << "No symbol table found in " << libPath << std::endl;
        elf_end(elf);
        close(fd);
        return;
    }

    Elf_Data *data = elf_getdata(scn, nullptr);
    if (!data) {
        std::cerr << "elf_getdata() failed: " << elf_errmsg(-1) << std::endl;
        elf_end(elf);
        close(fd);
        return;
    }

    std::ofstream outFile(outputFile);
    if (!outFile.is_open()) {
        std::cerr << "Failed to open output file: " << outputFile << std::endl;
        elf_end(elf);
        close(fd);
        return;
    }

    int count = shdr.sh_size / shdr.sh_entsize;
    for (int i = 0; i < count; ++i) {
        GElf_Sym sym;
        gelf_getsym(data, i, &sym);
        if (GELF_ST_TYPE(sym.st_info) == STT_FUNC) {
            const char *name = elf_strptr(elf, shdr.sh_link, sym.st_name);
            if (name) {
                outFile << i << ":" << name << std::endl;
            }
        }
    }

    outFile.close();
    elf_end(elf);
    close(fd);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <shared-library> <output-file>" << std::endl;
        return 1;
    }

    extractFunctionNames(argv[1], argv[2]);
    return 0;
}