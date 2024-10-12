; NOTE: Assertions have been autogenerated by utils/update_analyze_test_checks.py UTC_ARGS: --version 4
; RUN: opt -passes="print<cost-model>" 2>&1 -disable-output -mtriple=arm64-apple-macosx < %s | FileCheck %s

define void @vec3_i32(<3 x i32> %a, <3 x i32> %b, ptr %src, ptr %dst) {
; CHECK-LABEL: 'vec3_i32'
; CHECK-NEXT:  Cost Model: Found an estimated cost of 2 for instruction: %l = load <3 x i32>, ptr %src, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %add = add <3 x i32> %l, %b
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %cmp = icmp uge <3 x i32> %add, %a
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %sub = sub <3 x i32> %add, %a
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %sel = select <3 x i1> %cmp, <3 x i32> %add, <3 x i32> %sub
; CHECK-NEXT:  Cost Model: Found an estimated cost of 2 for instruction: store <3 x i32> %sel, ptr %dst, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 0 for instruction: ret void
;
  %l = load <3 x i32>, ptr %src, align 1
  %add = add <3 x i32> %l, %b
  %cmp = icmp uge <3 x i32> %add, %a
  %sub = sub <3 x i32> %add, %a
  %sel = select <3 x i1> %cmp, <3 x i32> %add, <3 x i32> %sub
  store <3 x i32> %sel, ptr %dst, align 1
  ret void
}

define void @vec3_i32_default_alignment(<3 x i32> %a, <3 x i32> %b, ptr %src, ptr %dst) {
; CHECK-LABEL: 'vec3_i32_default_alignment'
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %l = load <3 x i32>, ptr %src, align 16
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %add = add <3 x i32> %l, %b
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %cmp = icmp uge <3 x i32> %add, %a
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %sub = sub <3 x i32> %add, %a
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %sel = select <3 x i1> %cmp, <3 x i32> %add, <3 x i32> %sub
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: store <3 x i32> %sel, ptr %dst, align 16
; CHECK-NEXT:  Cost Model: Found an estimated cost of 0 for instruction: ret void
;
  %l = load <3 x i32>, ptr %src
  %add = add <3 x i32> %l, %b
  %cmp = icmp uge <3 x i32> %add, %a
  %sub = sub <3 x i32> %add, %a
  %sel = select <3 x i1> %cmp, <3 x i32> %add, <3 x i32> %sub
  store <3 x i32> %sel, ptr %dst
  ret void
}

define void @vec3_i16(<3 x i16> %a, <3 x i16> %b, ptr %src, ptr %dst) {
; CHECK-LABEL: 'vec3_i16'
; CHECK-NEXT:  Cost Model: Found an estimated cost of 2 for instruction: %l = load <3 x i16>, ptr %src, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %add = add <3 x i16> %l, %b
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %cmp = icmp uge <3 x i16> %add, %a
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %sub = sub <3 x i16> %add, %a
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %sel = select <3 x i1> %cmp, <3 x i16> %add, <3 x i16> %sub
; CHECK-NEXT:  Cost Model: Found an estimated cost of 2 for instruction: store <3 x i16> %sel, ptr %dst, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 0 for instruction: ret void
;
  %l = load <3 x i16>, ptr %src, align 1
  %add = add <3 x i16> %l, %b
  %cmp = icmp uge <3 x i16> %add, %a
  %sub = sub <3 x i16> %add, %a
  %sel = select <3 x i1> %cmp, <3 x i16> %add, <3 x i16> %sub
  store <3 x i16> %sel, ptr %dst, align 1
  ret void
}

define void @vec7_i16(ptr %src, ptr %dst) {
; CHECK-LABEL: 'vec7_i16'
; CHECK-NEXT:  Cost Model: Found an estimated cost of 3 for instruction: %l = load <7 x i16>, ptr %src, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %add = add <7 x i16> %l, %l
; CHECK-NEXT:  Cost Model: Found an estimated cost of 3 for instruction: store <7 x i16> %add, ptr %dst, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 0 for instruction: ret void
;
  %l = load <7 x i16>, ptr %src, align 1
  %add = add <7 x i16> %l, %l
  store <7 x i16> %add, ptr %dst, align 1
  ret void
}

define void @vec6_i16(ptr %src, ptr %dst) {
; CHECK-LABEL: 'vec6_i16'
; CHECK-NEXT:  Cost Model: Found an estimated cost of 2 for instruction: %l = load <6 x i16>, ptr %src, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %add = add <6 x i16> %l, %l
; CHECK-NEXT:  Cost Model: Found an estimated cost of 2 for instruction: store <6 x i16> %add, ptr %dst, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 0 for instruction: ret void
;
  %l = load <6 x i16>, ptr %src, align 1
  %add = add <6 x i16> %l, %l
  store <6 x i16> %add, ptr %dst, align 1
  ret void
}

define void @vec5_i16(ptr %src, ptr %dst) {
; CHECK-LABEL: 'vec5_i16'
; CHECK-NEXT:  Cost Model: Found an estimated cost of 2 for instruction: %l = load <5 x i16>, ptr %src, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %add = add <5 x i16> %l, %l
; CHECK-NEXT:  Cost Model: Found an estimated cost of 2 for instruction: store <5 x i16> %add, ptr %dst, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 0 for instruction: ret void
;
  %l = load <5 x i16>, ptr %src, align 1
  %add = add <5 x i16> %l, %l
  store <5 x i16> %add, ptr %dst, align 1
  ret void
}

define void @vec3_i16_zext_i32(<3 x i32> %a, <3 x i32> %b, ptr %src, ptr %dst) {
; CHECK-LABEL: 'vec3_i16_zext_i32'
; CHECK-NEXT:  Cost Model: Found an estimated cost of 2 for instruction: %l = load <3 x i16>, ptr %src, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %l.ext = zext <3 x i16> %l to <3 x i32>
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %add = add <3 x i32> %l.ext, %b
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %sub = sub <3 x i32> %add, %a
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %sub.trunc = trunc <3 x i32> %sub to <3 x i16>
; CHECK-NEXT:  Cost Model: Found an estimated cost of 2 for instruction: store <3 x i16> %sub.trunc, ptr %dst, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 0 for instruction: ret void
;
  %l = load <3 x i16>, ptr %src, align 1
  %l.ext = zext <3 x i16> %l to <3 x i32>
  %add = add <3 x i32> %l.ext, %b
  %sub = sub <3 x i32> %add, %a
  %sub.trunc = trunc <3 x i32> %sub to <3 x i16>
  store <3 x i16> %sub.trunc, ptr %dst, align 1
  ret void
}

define void @vec3_i8(<3 x i8> %a, <3 x i8> %b, ptr %src, ptr %dst) {
; CHECK-LABEL: 'vec3_i8'
; CHECK-NEXT:  Cost Model: Found an estimated cost of 6 for instruction: %l = load <3 x i8>, ptr %src, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %add = add <3 x i8> %l, %b
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %cmp = icmp uge <3 x i8> %add, %a
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %sub = sub <3 x i8> %add, %a
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %sel = select <3 x i1> %cmp, <3 x i8> %add, <3 x i8> %sub
; CHECK-NEXT:  Cost Model: Found an estimated cost of 6 for instruction: store <3 x i8> %sel, ptr %dst, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 0 for instruction: ret void
;
  %l = load <3 x i8>, ptr %src, align 1
  %add = add <3 x i8> %l, %b
  %cmp = icmp uge <3 x i8> %add, %a
  %sub = sub <3 x i8> %add, %a
  %sel = select <3 x i1> %cmp, <3 x i8> %add, <3 x i8> %sub
  store <3 x i8> %sel, ptr %dst, align 1
  ret void
}

define void @vec3_i8_zext_i32(<3 x i32> %a, <3 x i32> %b, ptr %src, ptr %dst) {
; CHECK-LABEL: 'vec3_i8_zext_i32'
; CHECK-NEXT:  Cost Model: Found an estimated cost of 6 for instruction: %l = load <3 x i8>, ptr %src, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %l.ext = zext <3 x i8> %l to <3 x i32>
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %add = add <3 x i32> %l.ext, %b
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %sub = sub <3 x i32> %add, %a
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %sub.trunc = trunc <3 x i32> %sub to <3 x i8>
; CHECK-NEXT:  Cost Model: Found an estimated cost of 6 for instruction: store <3 x i8> %sub.trunc, ptr %dst, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 0 for instruction: ret void
;
  %l = load <3 x i8>, ptr %src, align 1
  %l.ext = zext <3 x i8> %l to <3 x i32>
  %add = add <3 x i32> %l.ext, %b
  %sub = sub <3 x i32> %add, %a
  %sub.trunc = trunc <3 x i32> %sub to <3 x i8>
  store <3 x i8> %sub.trunc, ptr %dst, align 1
  ret void
}

define void @vec3_i8_sext_i32(<3 x i32> %a, <3 x i32> %b, ptr %src, ptr %dst) {
; CHECK-LABEL: 'vec3_i8_sext_i32'
; CHECK-NEXT:  Cost Model: Found an estimated cost of 6 for instruction: %l = load <3 x i8>, ptr %src, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %l.ext = sext <3 x i8> %l to <3 x i32>
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %add = add <3 x i32> %l.ext, %b
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %sub = sub <3 x i32> %add, %a
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %sub.trunc = trunc <3 x i32> %sub to <3 x i8>
; CHECK-NEXT:  Cost Model: Found an estimated cost of 6 for instruction: store <3 x i8> %sub.trunc, ptr %dst, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 0 for instruction: ret void
;
  %l = load <3 x i8>, ptr %src, align 1
  %l.ext = sext <3 x i8> %l to <3 x i32>
  %add = add <3 x i32> %l.ext, %b
  %sub = sub <3 x i32> %add, %a
  %sub.trunc = trunc <3 x i32> %sub to <3 x i8>
  store <3 x i8> %sub.trunc, ptr %dst, align 1
  ret void
}

define void @vec3_i30(<3 x i30> %a, <3 x i30> %b, ptr %src, ptr %dst) {
; CHECK-LABEL: 'vec3_i30'
; CHECK-NEXT:  Cost Model: Found an estimated cost of 6 for instruction: %l = load <3 x i30>, ptr %src, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %add = add <3 x i30> %l, %b
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %sub = sub <3 x i30> %add, %a
; CHECK-NEXT:  Cost Model: Found an estimated cost of 6 for instruction: store <3 x i30> %sub, ptr %dst, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 0 for instruction: ret void
;
  %l = load <3 x i30>, ptr %src, align 1
  %add = add <3 x i30> %l, %b
  %sub = sub <3 x i30> %add, %a
  store <3 x i30> %sub, ptr %dst, align 1
  ret void
}

define void @vec3_float(<3 x float> %a, <3 x float> %b, ptr %src, ptr %dst) {
; CHECK-LABEL: 'vec3_float'
; CHECK-NEXT:  Cost Model: Found an estimated cost of 2 for instruction: %l = load <3 x float>, ptr %src, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %add = fadd <3 x float> %l, %b
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %sub = fsub <3 x float> %add, %a
; CHECK-NEXT:  Cost Model: Found an estimated cost of 2 for instruction: store <3 x float> %sub, ptr %dst, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 0 for instruction: ret void
;
  %l = load <3 x float>, ptr %src, align 1
  %add = fadd <3 x float> %l, %b
  %sub = fsub <3 x float> %add, %a
  store <3 x float> %sub, ptr %dst, align 1
  ret void
}

define void @vec3_half(<3 x half> %a, <3 x half> %b, ptr %src, ptr %dst) {
; CHECK-LABEL: 'vec3_half'
; CHECK-NEXT:  Cost Model: Found an estimated cost of 2 for instruction: %l = load <3 x half>, ptr %src, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 2 for instruction: %add = fadd <3 x half> %l, %b
; CHECK-NEXT:  Cost Model: Found an estimated cost of 2 for instruction: %sub = fsub <3 x half> %add, %a
; CHECK-NEXT:  Cost Model: Found an estimated cost of 2 for instruction: store <3 x half> %sub, ptr %dst, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 0 for instruction: ret void
;
  %l = load <3 x half>, ptr %src, align 1
  %add = fadd <3 x half> %l, %b
  %sub = fsub <3 x half> %add, %a
  store <3 x half> %sub, ptr %dst, align 1
  ret void
}

define void @vec15_i8(ptr %src, ptr %dst) {
; CHECK-LABEL: 'vec15_i8'
; CHECK-NEXT:  Cost Model: Found an estimated cost of 4 for instruction: %l = load <15 x i8>, ptr %src, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %add = add <15 x i8> %l, %l
; CHECK-NEXT:  Cost Model: Found an estimated cost of 4 for instruction: store <15 x i8> %add, ptr %dst, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 0 for instruction: ret void
;
  %l = load <15 x i8>, ptr %src, align 1
  %add = add <15 x i8> %l, %l
  store <15 x i8> %add, ptr %dst, align 1
  ret void
}

define void @vec14_i8(ptr %src, ptr %dst) {
; CHECK-LABEL: 'vec14_i8'
; CHECK-NEXT:  Cost Model: Found an estimated cost of 3 for instruction: %l = load <14 x i8>, ptr %src, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %add = add <14 x i8> %l, %l
; CHECK-NEXT:  Cost Model: Found an estimated cost of 3 for instruction: store <14 x i8> %add, ptr %dst, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 0 for instruction: ret void
;
  %l = load <14 x i8>, ptr %src, align 1
  %add = add <14 x i8> %l, %l
  store <14 x i8> %add, ptr %dst, align 1
  ret void
}

define void @vec13_i8(ptr %src, ptr %dst) {
; CHECK-LABEL: 'vec13_i8'
; CHECK-NEXT:  Cost Model: Found an estimated cost of 3 for instruction: %l = load <13 x i8>, ptr %src, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %add = add <13 x i8> %l, %l
; CHECK-NEXT:  Cost Model: Found an estimated cost of 3 for instruction: store <13 x i8> %add, ptr %dst, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 0 for instruction: ret void
;
  %l = load <13 x i8>, ptr %src, align 1
  %add = add <13 x i8> %l, %l
  store <13 x i8> %add, ptr %dst, align 1
  ret void
}

define void @vec12_i8(ptr %src, ptr %dst) {
; CHECK-LABEL: 'vec12_i8'
; CHECK-NEXT:  Cost Model: Found an estimated cost of 2 for instruction: %l = load <12 x i8>, ptr %src, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %add = add <12 x i8> %l, %l
; CHECK-NEXT:  Cost Model: Found an estimated cost of 2 for instruction: store <12 x i8> %add, ptr %dst, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 0 for instruction: ret void
;
  %l = load <12 x i8>, ptr %src, align 1
  %add = add <12 x i8> %l, %l
  store <12 x i8> %add, ptr %dst, align 1
  ret void
}

define void @vec11_i8(ptr %src, ptr %dst) {
; CHECK-LABEL: 'vec11_i8'
; CHECK-NEXT:  Cost Model: Found an estimated cost of 3 for instruction: %l = load <11 x i8>, ptr %src, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %add = add <11 x i8> %l, %l
; CHECK-NEXT:  Cost Model: Found an estimated cost of 3 for instruction: store <11 x i8> %add, ptr %dst, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 0 for instruction: ret void
;
  %l = load <11 x i8>, ptr %src, align 1
  %add = add <11 x i8> %l, %l
  store <11 x i8> %add, ptr %dst, align 1
  ret void
}

define void @vec7_i8(<7 x i8> %a, <7 x i8> %b, ptr %src, ptr %dst) {
; CHECK-LABEL: 'vec7_i8'
; CHECK-NEXT:  Cost Model: Found an estimated cost of 3 for instruction: %l = load <7 x i8>, ptr %src, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %add = add <7 x i8> %l, %b
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %sub = sub <7 x i8> %add, %a
; CHECK-NEXT:  Cost Model: Found an estimated cost of 3 for instruction: store <7 x i8> %sub, ptr %dst, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 0 for instruction: ret void
;
  %l = load <7 x i8>, ptr %src, align 1
  %add = add <7 x i8> %l, %b
  %sub = sub <7 x i8> %add, %a
  store <7 x i8> %sub, ptr %dst, align 1
  ret void
}

define void @vec6_i8(ptr %src, ptr %dst) {
; CHECK-LABEL: 'vec6_i8'
; CHECK-NEXT:  Cost Model: Found an estimated cost of 2 for instruction: %l = load <6 x i8>, ptr %src, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %add = add <6 x i8> %l, %l
; CHECK-NEXT:  Cost Model: Found an estimated cost of 2 for instruction: store <6 x i8> %add, ptr %dst, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 0 for instruction: ret void
;
  %l = load <6 x i8>, ptr %src, align 1
  %add = add <6 x i8> %l, %l
  store <6 x i8> %add, ptr %dst, align 1
  ret void
}

define void @vec5_i8(ptr %src, ptr %dst) {
; CHECK-LABEL: 'vec5_i8'
; CHECK-NEXT:  Cost Model: Found an estimated cost of 2 for instruction: %l = load <5 x i8>, ptr %src, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 1 for instruction: %add = add <5 x i8> %l, %l
; CHECK-NEXT:  Cost Model: Found an estimated cost of 2 for instruction: store <5 x i8> %add, ptr %dst, align 1
; CHECK-NEXT:  Cost Model: Found an estimated cost of 0 for instruction: ret void
;
  %l = load <5 x i8>, ptr %src, align 1
  %add = add <5 x i8> %l, %l
  store <5 x i8> %add, ptr %dst, align 1
  ret void
}

