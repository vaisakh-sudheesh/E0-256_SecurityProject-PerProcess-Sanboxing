// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: amdgpu-registered-target
// RUN: %clang_cc1 -triple amdgcn-unknown-unknown -target-cpu gfx1200 -target-feature +wavefrontsize64 -S -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-GFX1200

typedef half   v4h   __attribute__((ext_vector_type(4)));
typedef short  v4s   __attribute__((ext_vector_type(4)));

// Wave64

//
// amdgcn_global_load_tr
//

// CHECK-GFX1200-LABEL: @test_amdgcn_global_load_tr_i32(
// CHECK-GFX1200-NEXT:  entry:
// CHECK-GFX1200-NEXT:    [[TMP0:%.*]] = tail call i32 @llvm.amdgcn.global.load.tr.i32(ptr addrspace(1) [[INPTR:%.*]])
// CHECK-GFX1200-NEXT:    ret i32 [[TMP0]]
//
int test_amdgcn_global_load_tr_i32(global int* inptr)
{
  return __builtin_amdgcn_global_load_tr_i32(inptr);
}

//
// amdgcn_global_load_tr
//

// CHECK-GFX1200-LABEL: @test_amdgcn_global_load_tr_v4i16(
// CHECK-GFX1200-NEXT:  entry:
// CHECK-GFX1200-NEXT:    [[TMP0:%.*]] = tail call <4 x i16> @llvm.amdgcn.global.load.tr.v4i16(ptr addrspace(1) [[INPTR:%.*]])
// CHECK-GFX1200-NEXT:    ret <4 x i16> [[TMP0]]
//
v4s test_amdgcn_global_load_tr_v4i16(global v4s* inptr)
{
  return __builtin_amdgcn_global_load_tr_v4i16(inptr);
}

// CHECK-GFX1200-LABEL: @test_amdgcn_global_load_tr_v4f16(
// CHECK-GFX1200-NEXT:  entry:
// CHECK-GFX1200-NEXT:    [[TMP0:%.*]] = tail call <4 x half> @llvm.amdgcn.global.load.tr.v4f16(ptr addrspace(1) [[INPTR:%.*]])
// CHECK-GFX1200-NEXT:    ret <4 x half> [[TMP0]]
//
v4h test_amdgcn_global_load_tr_v4f16(global v4h* inptr)
{
  return __builtin_amdgcn_global_load_tr_v4f16(inptr);
}
