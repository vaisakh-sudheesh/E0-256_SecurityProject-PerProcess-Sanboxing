// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --function-signature --include-generated-funcs --replace-value-regex "__omp_offloading_[0-9a-z]+_[0-9a-z]+" "reduction_size[.].+[.]" "pl_cond[.].+[.|,]" --prefix-filecheck-ir-name _
// RUN: %clang_cc1 -verify -fopenmp -x c -triple x86_64-unknown-unknown -emit-llvm %s -o - | FileCheck %s
// RUN: %clang_cc1 -fopenmp -x c -triple x86_64-unknown-unknown -emit-pch -o %t %s
// RUN: %clang_cc1 -fopenmp -x c -triple x86_64-unknown-unknown -include-pch %t -verify %s -emit-llvm -o - | FileCheck %s

// RUN: %clang_cc1 -verify -fopenmp-simd -x c -triple x86_64-unknown-unknown -emit-llvm %s -o - | FileCheck --check-prefix SIMD-ONLY0 %s
// RUN: %clang_cc1 -fopenmp-simd -x c -triple x86_64-unknown-unknown -emit-pch -o %t %s
// RUN: %clang_cc1 -fopenmp-simd -x c -triple x86_64-unknown-unknown -include-pch %t -verify %s -emit-llvm -o - | FileCheck --check-prefix SIMD-ONLY0 %s
// expected-no-diagnostics
#ifndef HEADER
#define HEADER

void collapsed(int mp) {
#pragma omp for collapse(3)
  for (int j = 0; j < mp; ++j) {
    for (int i = j; i < mp; ++i) {
      for (int i0 = 0; i0 < 10; ++i0) {
        ;
      }
    }
  }
}

#endif // HEADER
// CHECK-LABEL: define {{[^@]+}}@collapsed
// CHECK-SAME: (i32 noundef [[MP:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[MP_ADDR:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[DOTOMP_IV:%.*]] = alloca i64, align 8
// CHECK-NEXT:    [[TMP:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[_TMP1:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[_TMP2:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[DOTCAPTURE_EXPR_:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[DOTLB_MIN:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[DOTLB_MAX:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[DOTMIN_LESS_MAX:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[DOTUPPER:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[DOTLOWER:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[DOTCAPTURE_EXPR_3:%.*]] = alloca i64, align 8
// CHECK-NEXT:    [[J:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[I:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[I0:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[_TMP15:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[DOTOMP_LB:%.*]] = alloca i64, align 8
// CHECK-NEXT:    [[DOTOMP_UB:%.*]] = alloca i64, align 8
// CHECK-NEXT:    [[DOTOMP_STRIDE:%.*]] = alloca i64, align 8
// CHECK-NEXT:    [[DOTOMP_IS_LAST:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[J19:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[I20:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[I021:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[TMP0:%.*]] = call i32 @__kmpc_global_thread_num(ptr @[[GLOB2:[0-9]+]])
// CHECK-NEXT:    store i32 [[MP]], ptr [[MP_ADDR]], align 4
// CHECK-NEXT:    [[TMP1:%.*]] = load i32, ptr [[MP_ADDR]], align 4
// CHECK-NEXT:    store i32 [[TMP1]], ptr [[DOTCAPTURE_EXPR_]], align 4
// CHECK-NEXT:    store i32 0, ptr [[TMP]], align 4
// CHECK-NEXT:    [[TMP2:%.*]] = load i32, ptr [[TMP]], align 4
// CHECK-NEXT:    store i32 [[TMP2]], ptr [[DOTLB_MIN]], align 4
// CHECK-NEXT:    [[TMP3:%.*]] = load i32, ptr [[DOTCAPTURE_EXPR_]], align 4
// CHECK-NEXT:    [[SUB:%.*]] = sub nsw i32 [[TMP3]], 1
// CHECK-NEXT:    [[DIV:%.*]] = sdiv i32 [[SUB]], 1
// CHECK-NEXT:    [[MUL:%.*]] = mul nsw i32 [[DIV]], 1
// CHECK-NEXT:    [[ADD:%.*]] = add nsw i32 0, [[MUL]]
// CHECK-NEXT:    store i32 [[ADD]], ptr [[TMP]], align 4
// CHECK-NEXT:    [[TMP4:%.*]] = load i32, ptr [[TMP]], align 4
// CHECK-NEXT:    store i32 [[TMP4]], ptr [[DOTLB_MAX]], align 4
// CHECK-NEXT:    [[TMP5:%.*]] = load i32, ptr [[DOTLB_MIN]], align 4
// CHECK-NEXT:    [[TMP6:%.*]] = load i32, ptr [[DOTLB_MAX]], align 4
// CHECK-NEXT:    [[CMP:%.*]] = icmp slt i32 [[TMP5]], [[TMP6]]
// CHECK-NEXT:    [[CONV:%.*]] = zext i1 [[CMP]] to i32
// CHECK-NEXT:    store i32 [[CONV]], ptr [[DOTMIN_LESS_MAX]], align 4
// CHECK-NEXT:    [[TMP7:%.*]] = load i32, ptr [[MP_ADDR]], align 4
// CHECK-NEXT:    store i32 [[TMP7]], ptr [[DOTUPPER]], align 4
// CHECK-NEXT:    [[TMP8:%.*]] = load i32, ptr [[DOTMIN_LESS_MAX]], align 4
// CHECK-NEXT:    [[TOBOOL:%.*]] = icmp ne i32 [[TMP8]], 0
// CHECK-NEXT:    br i1 [[TOBOOL]], label [[COND_TRUE:%.*]], label [[COND_FALSE:%.*]]
// CHECK:       cond.true:
// CHECK-NEXT:    [[TMP9:%.*]] = load i32, ptr [[DOTLB_MIN]], align 4
// CHECK-NEXT:    br label [[COND_END:%.*]]
// CHECK:       cond.false:
// CHECK-NEXT:    [[TMP10:%.*]] = load i32, ptr [[DOTLB_MAX]], align 4
// CHECK-NEXT:    br label [[COND_END]]
// CHECK:       cond.end:
// CHECK-NEXT:    [[COND:%.*]] = phi i32 [ [[TMP9]], [[COND_TRUE]] ], [ [[TMP10]], [[COND_FALSE]] ]
// CHECK-NEXT:    store i32 [[COND]], ptr [[TMP]], align 4
// CHECK-NEXT:    store i32 [[COND]], ptr [[DOTLOWER]], align 4
// CHECK-NEXT:    [[TMP11:%.*]] = load i32, ptr [[DOTCAPTURE_EXPR_]], align 4
// CHECK-NEXT:    [[SUB4:%.*]] = sub nsw i32 [[TMP11]], 0
// CHECK-NEXT:    [[DIV5:%.*]] = sdiv i32 [[SUB4]], 1
// CHECK-NEXT:    [[CONV6:%.*]] = sext i32 [[DIV5]] to i64
// CHECK-NEXT:    [[TMP12:%.*]] = load i32, ptr [[DOTUPPER]], align 4
// CHECK-NEXT:    [[TMP13:%.*]] = load i32, ptr [[DOTLOWER]], align 4
// CHECK-NEXT:    [[SUB7:%.*]] = sub i32 [[TMP12]], [[TMP13]]
// CHECK-NEXT:    [[SUB8:%.*]] = sub i32 [[SUB7]], 1
// CHECK-NEXT:    [[ADD9:%.*]] = add i32 [[SUB8]], 1
// CHECK-NEXT:    [[DIV10:%.*]] = udiv i32 [[ADD9]], 1
// CHECK-NEXT:    [[CONV11:%.*]] = zext i32 [[DIV10]] to i64
// CHECK-NEXT:    [[MUL12:%.*]] = mul nsw i64 [[CONV6]], [[CONV11]]
// CHECK-NEXT:    [[MUL13:%.*]] = mul nsw i64 [[MUL12]], 10
// CHECK-NEXT:    [[SUB14:%.*]] = sub nsw i64 [[MUL13]], 1
// CHECK-NEXT:    store i64 [[SUB14]], ptr [[DOTCAPTURE_EXPR_3]], align 8
// CHECK-NEXT:    store i32 0, ptr [[J]], align 4
// CHECK-NEXT:    [[TMP14:%.*]] = load i32, ptr [[J]], align 4
// CHECK-NEXT:    store i32 [[TMP14]], ptr [[I]], align 4
// CHECK-NEXT:    store i32 0, ptr [[I0]], align 4
// CHECK-NEXT:    store i32 0, ptr [[_TMP15]], align 4
// CHECK-NEXT:    [[TMP15:%.*]] = load i32, ptr [[DOTCAPTURE_EXPR_]], align 4
// CHECK-NEXT:    [[CMP16:%.*]] = icmp slt i32 0, [[TMP15]]
// CHECK-NEXT:    br i1 [[CMP16]], label [[OMP_PRECOND_THEN:%.*]], label [[OMP_PRECOND_END:%.*]]
// CHECK:       omp.precond.then:
// CHECK-NEXT:    store i64 0, ptr [[DOTOMP_LB]], align 8
// CHECK-NEXT:    [[TMP16:%.*]] = load i64, ptr [[DOTCAPTURE_EXPR_3]], align 8
// CHECK-NEXT:    store i64 [[TMP16]], ptr [[DOTOMP_UB]], align 8
// CHECK-NEXT:    store i64 1, ptr [[DOTOMP_STRIDE]], align 8
// CHECK-NEXT:    store i32 0, ptr [[DOTOMP_IS_LAST]], align 4
// CHECK-NEXT:    call void @__kmpc_for_static_init_8(ptr @[[GLOB1:[0-9]+]], i32 [[TMP0]], i32 34, ptr [[DOTOMP_IS_LAST]], ptr [[DOTOMP_LB]], ptr [[DOTOMP_UB]], ptr [[DOTOMP_STRIDE]], i64 1, i64 1)
// CHECK-NEXT:    [[TMP17:%.*]] = load i64, ptr [[DOTOMP_UB]], align 8
// CHECK-NEXT:    [[TMP18:%.*]] = load i64, ptr [[DOTCAPTURE_EXPR_3]], align 8
// CHECK-NEXT:    [[CMP22:%.*]] = icmp sgt i64 [[TMP17]], [[TMP18]]
// CHECK-NEXT:    br i1 [[CMP22]], label [[COND_TRUE24:%.*]], label [[COND_FALSE25:%.*]]
// CHECK:       cond.true24:
// CHECK-NEXT:    [[TMP19:%.*]] = load i64, ptr [[DOTCAPTURE_EXPR_3]], align 8
// CHECK-NEXT:    br label [[COND_END26:%.*]]
// CHECK:       cond.false25:
// CHECK-NEXT:    [[TMP20:%.*]] = load i64, ptr [[DOTOMP_UB]], align 8
// CHECK-NEXT:    br label [[COND_END26]]
// CHECK:       cond.end26:
// CHECK-NEXT:    [[COND27:%.*]] = phi i64 [ [[TMP19]], [[COND_TRUE24]] ], [ [[TMP20]], [[COND_FALSE25]] ]
// CHECK-NEXT:    store i64 [[COND27]], ptr [[DOTOMP_UB]], align 8
// CHECK-NEXT:    [[TMP21:%.*]] = load i64, ptr [[DOTOMP_LB]], align 8
// CHECK-NEXT:    store i64 [[TMP21]], ptr [[DOTOMP_IV]], align 8
// CHECK-NEXT:    br label [[OMP_INNER_FOR_COND:%.*]]
// CHECK:       omp.inner.for.cond:
// CHECK-NEXT:    [[TMP22:%.*]] = load i64, ptr [[DOTOMP_IV]], align 8
// CHECK-NEXT:    [[TMP23:%.*]] = load i64, ptr [[DOTOMP_UB]], align 8
// CHECK-NEXT:    [[CMP28:%.*]] = icmp sle i64 [[TMP22]], [[TMP23]]
// CHECK-NEXT:    br i1 [[CMP28]], label [[OMP_INNER_FOR_BODY:%.*]], label [[OMP_INNER_FOR_END:%.*]]
// CHECK:       omp.inner.for.body:
// CHECK-NEXT:    [[TMP24:%.*]] = load i64, ptr [[DOTOMP_IV]], align 8
// CHECK-NEXT:    [[TMP25:%.*]] = load i32, ptr [[DOTUPPER]], align 4
// CHECK-NEXT:    [[TMP26:%.*]] = load i32, ptr [[DOTLOWER]], align 4
// CHECK-NEXT:    [[SUB30:%.*]] = sub i32 [[TMP25]], [[TMP26]]
// CHECK-NEXT:    [[SUB31:%.*]] = sub i32 [[SUB30]], 1
// CHECK-NEXT:    [[ADD32:%.*]] = add i32 [[SUB31]], 1
// CHECK-NEXT:    [[DIV33:%.*]] = udiv i32 [[ADD32]], 1
// CHECK-NEXT:    [[MUL34:%.*]] = mul i32 1, [[DIV33]]
// CHECK-NEXT:    [[MUL35:%.*]] = mul i32 [[MUL34]], 10
// CHECK-NEXT:    [[CONV36:%.*]] = zext i32 [[MUL35]] to i64
// CHECK-NEXT:    [[DIV37:%.*]] = sdiv i64 [[TMP24]], [[CONV36]]
// CHECK-NEXT:    [[MUL38:%.*]] = mul nsw i64 [[DIV37]], 1
// CHECK-NEXT:    [[ADD39:%.*]] = add nsw i64 0, [[MUL38]]
// CHECK-NEXT:    [[CONV40:%.*]] = trunc i64 [[ADD39]] to i32
// CHECK-NEXT:    store i32 [[CONV40]], ptr [[J19]], align 4
// CHECK-NEXT:    [[TMP27:%.*]] = load i32, ptr [[J19]], align 4
// CHECK-NEXT:    [[CONV41:%.*]] = sext i32 [[TMP27]] to i64
// CHECK-NEXT:    [[TMP28:%.*]] = load i64, ptr [[DOTOMP_IV]], align 8
// CHECK-NEXT:    [[TMP29:%.*]] = load i64, ptr [[DOTOMP_IV]], align 8
// CHECK-NEXT:    [[TMP30:%.*]] = load i32, ptr [[DOTUPPER]], align 4
// CHECK-NEXT:    [[TMP31:%.*]] = load i32, ptr [[DOTLOWER]], align 4
// CHECK-NEXT:    [[SUB42:%.*]] = sub i32 [[TMP30]], [[TMP31]]
// CHECK-NEXT:    [[SUB43:%.*]] = sub i32 [[SUB42]], 1
// CHECK-NEXT:    [[ADD44:%.*]] = add i32 [[SUB43]], 1
// CHECK-NEXT:    [[DIV45:%.*]] = udiv i32 [[ADD44]], 1
// CHECK-NEXT:    [[MUL46:%.*]] = mul i32 1, [[DIV45]]
// CHECK-NEXT:    [[MUL47:%.*]] = mul i32 [[MUL46]], 10
// CHECK-NEXT:    [[CONV48:%.*]] = zext i32 [[MUL47]] to i64
// CHECK-NEXT:    [[DIV49:%.*]] = sdiv i64 [[TMP29]], [[CONV48]]
// CHECK-NEXT:    [[TMP32:%.*]] = load i32, ptr [[DOTUPPER]], align 4
// CHECK-NEXT:    [[TMP33:%.*]] = load i32, ptr [[DOTLOWER]], align 4
// CHECK-NEXT:    [[SUB50:%.*]] = sub i32 [[TMP32]], [[TMP33]]
// CHECK-NEXT:    [[SUB51:%.*]] = sub i32 [[SUB50]], 1
// CHECK-NEXT:    [[ADD52:%.*]] = add i32 [[SUB51]], 1
// CHECK-NEXT:    [[DIV53:%.*]] = udiv i32 [[ADD52]], 1
// CHECK-NEXT:    [[MUL54:%.*]] = mul i32 1, [[DIV53]]
// CHECK-NEXT:    [[MUL55:%.*]] = mul i32 [[MUL54]], 10
// CHECK-NEXT:    [[CONV56:%.*]] = zext i32 [[MUL55]] to i64
// CHECK-NEXT:    [[MUL57:%.*]] = mul nsw i64 [[DIV49]], [[CONV56]]
// CHECK-NEXT:    [[SUB58:%.*]] = sub nsw i64 [[TMP28]], [[MUL57]]
// CHECK-NEXT:    [[DIV59:%.*]] = sdiv i64 [[SUB58]], 10
// CHECK-NEXT:    [[MUL60:%.*]] = mul nsw i64 [[DIV59]], 1
// CHECK-NEXT:    [[ADD61:%.*]] = add nsw i64 [[CONV41]], [[MUL60]]
// CHECK-NEXT:    [[CONV62:%.*]] = trunc i64 [[ADD61]] to i32
// CHECK-NEXT:    store i32 [[CONV62]], ptr [[I20]], align 4
// CHECK-NEXT:    [[TMP34:%.*]] = load i64, ptr [[DOTOMP_IV]], align 8
// CHECK-NEXT:    [[TMP35:%.*]] = load i64, ptr [[DOTOMP_IV]], align 8
// CHECK-NEXT:    [[TMP36:%.*]] = load i32, ptr [[DOTUPPER]], align 4
// CHECK-NEXT:    [[TMP37:%.*]] = load i32, ptr [[DOTLOWER]], align 4
// CHECK-NEXT:    [[SUB63:%.*]] = sub i32 [[TMP36]], [[TMP37]]
// CHECK-NEXT:    [[SUB64:%.*]] = sub i32 [[SUB63]], 1
// CHECK-NEXT:    [[ADD65:%.*]] = add i32 [[SUB64]], 1
// CHECK-NEXT:    [[DIV66:%.*]] = udiv i32 [[ADD65]], 1
// CHECK-NEXT:    [[MUL67:%.*]] = mul i32 1, [[DIV66]]
// CHECK-NEXT:    [[MUL68:%.*]] = mul i32 [[MUL67]], 10
// CHECK-NEXT:    [[CONV69:%.*]] = zext i32 [[MUL68]] to i64
// CHECK-NEXT:    [[DIV70:%.*]] = sdiv i64 [[TMP35]], [[CONV69]]
// CHECK-NEXT:    [[TMP38:%.*]] = load i32, ptr [[DOTUPPER]], align 4
// CHECK-NEXT:    [[TMP39:%.*]] = load i32, ptr [[DOTLOWER]], align 4
// CHECK-NEXT:    [[SUB71:%.*]] = sub i32 [[TMP38]], [[TMP39]]
// CHECK-NEXT:    [[SUB72:%.*]] = sub i32 [[SUB71]], 1
// CHECK-NEXT:    [[ADD73:%.*]] = add i32 [[SUB72]], 1
// CHECK-NEXT:    [[DIV74:%.*]] = udiv i32 [[ADD73]], 1
// CHECK-NEXT:    [[MUL75:%.*]] = mul i32 1, [[DIV74]]
// CHECK-NEXT:    [[MUL76:%.*]] = mul i32 [[MUL75]], 10
// CHECK-NEXT:    [[CONV77:%.*]] = zext i32 [[MUL76]] to i64
// CHECK-NEXT:    [[MUL78:%.*]] = mul nsw i64 [[DIV70]], [[CONV77]]
// CHECK-NEXT:    [[SUB79:%.*]] = sub nsw i64 [[TMP34]], [[MUL78]]
// CHECK-NEXT:    [[TMP40:%.*]] = load i64, ptr [[DOTOMP_IV]], align 8
// CHECK-NEXT:    [[TMP41:%.*]] = load i64, ptr [[DOTOMP_IV]], align 8
// CHECK-NEXT:    [[TMP42:%.*]] = load i32, ptr [[DOTUPPER]], align 4
// CHECK-NEXT:    [[TMP43:%.*]] = load i32, ptr [[DOTLOWER]], align 4
// CHECK-NEXT:    [[SUB80:%.*]] = sub i32 [[TMP42]], [[TMP43]]
// CHECK-NEXT:    [[SUB81:%.*]] = sub i32 [[SUB80]], 1
// CHECK-NEXT:    [[ADD82:%.*]] = add i32 [[SUB81]], 1
// CHECK-NEXT:    [[DIV83:%.*]] = udiv i32 [[ADD82]], 1
// CHECK-NEXT:    [[MUL84:%.*]] = mul i32 1, [[DIV83]]
// CHECK-NEXT:    [[MUL85:%.*]] = mul i32 [[MUL84]], 10
// CHECK-NEXT:    [[CONV86:%.*]] = zext i32 [[MUL85]] to i64
// CHECK-NEXT:    [[DIV87:%.*]] = sdiv i64 [[TMP41]], [[CONV86]]
// CHECK-NEXT:    [[TMP44:%.*]] = load i32, ptr [[DOTUPPER]], align 4
// CHECK-NEXT:    [[TMP45:%.*]] = load i32, ptr [[DOTLOWER]], align 4
// CHECK-NEXT:    [[SUB88:%.*]] = sub i32 [[TMP44]], [[TMP45]]
// CHECK-NEXT:    [[SUB89:%.*]] = sub i32 [[SUB88]], 1
// CHECK-NEXT:    [[ADD90:%.*]] = add i32 [[SUB89]], 1
// CHECK-NEXT:    [[DIV91:%.*]] = udiv i32 [[ADD90]], 1
// CHECK-NEXT:    [[MUL92:%.*]] = mul i32 1, [[DIV91]]
// CHECK-NEXT:    [[MUL93:%.*]] = mul i32 [[MUL92]], 10
// CHECK-NEXT:    [[CONV94:%.*]] = zext i32 [[MUL93]] to i64
// CHECK-NEXT:    [[MUL95:%.*]] = mul nsw i64 [[DIV87]], [[CONV94]]
// CHECK-NEXT:    [[SUB96:%.*]] = sub nsw i64 [[TMP40]], [[MUL95]]
// CHECK-NEXT:    [[DIV97:%.*]] = sdiv i64 [[SUB96]], 10
// CHECK-NEXT:    [[MUL98:%.*]] = mul nsw i64 [[DIV97]], 10
// CHECK-NEXT:    [[SUB99:%.*]] = sub nsw i64 [[SUB79]], [[MUL98]]
// CHECK-NEXT:    [[MUL100:%.*]] = mul nsw i64 [[SUB99]], 1
// CHECK-NEXT:    [[ADD101:%.*]] = add nsw i64 0, [[MUL100]]
// CHECK-NEXT:    [[CONV102:%.*]] = trunc i64 [[ADD101]] to i32
// CHECK-NEXT:    store i32 [[CONV102]], ptr [[I021]], align 4
// CHECK-NEXT:    [[TMP46:%.*]] = load i32, ptr [[I20]], align 4
// CHECK-NEXT:    [[TMP47:%.*]] = load i32, ptr [[MP_ADDR]], align 4
// CHECK-NEXT:    [[CMP103:%.*]] = icmp slt i32 [[TMP46]], [[TMP47]]
// CHECK-NEXT:    br i1 [[CMP103]], label [[OMP_BODY_NEXT:%.*]], label [[OMP_BODY_CONTINUE:%.*]]
// CHECK:       omp.body.next:
// CHECK-NEXT:    br label [[OMP_BODY_CONTINUE]]
// CHECK:       omp.body.continue:
// CHECK-NEXT:    br label [[OMP_INNER_FOR_INC:%.*]]
// CHECK:       omp.inner.for.inc:
// CHECK-NEXT:    [[TMP48:%.*]] = load i64, ptr [[DOTOMP_IV]], align 8
// CHECK-NEXT:    [[ADD105:%.*]] = add nsw i64 [[TMP48]], 1
// CHECK-NEXT:    store i64 [[ADD105]], ptr [[DOTOMP_IV]], align 8
// CHECK-NEXT:    br label [[OMP_INNER_FOR_COND]]
// CHECK:       omp.inner.for.end:
// CHECK-NEXT:    br label [[OMP_LOOP_EXIT:%.*]]
// CHECK:       omp.loop.exit:
// CHECK-NEXT:    call void @__kmpc_for_static_fini(ptr @[[GLOB1]], i32 [[TMP0]])
// CHECK-NEXT:    br label [[OMP_PRECOND_END]]
// CHECK:       omp.precond.end:
// CHECK-NEXT:    call void @__kmpc_barrier(ptr @[[GLOB3:[0-9]+]], i32 [[TMP0]])
// CHECK-NEXT:    ret void
//
//
// SIMD-ONLY0-LABEL: define {{[^@]+}}@collapsed
// SIMD-ONLY0-SAME: (i32 noundef [[MP:%.*]]) #[[ATTR0:[0-9]+]] {
// SIMD-ONLY0-NEXT:  entry:
// SIMD-ONLY0-NEXT:    [[MP_ADDR:%.*]] = alloca i32, align 4
// SIMD-ONLY0-NEXT:    [[J:%.*]] = alloca i32, align 4
// SIMD-ONLY0-NEXT:    [[I:%.*]] = alloca i32, align 4
// SIMD-ONLY0-NEXT:    [[I0:%.*]] = alloca i32, align 4
// SIMD-ONLY0-NEXT:    store i32 [[MP]], ptr [[MP_ADDR]], align 4
// SIMD-ONLY0-NEXT:    store i32 0, ptr [[J]], align 4
// SIMD-ONLY0-NEXT:    br label [[FOR_COND:%.*]]
// SIMD-ONLY0:       for.cond:
// SIMD-ONLY0-NEXT:    [[TMP0:%.*]] = load i32, ptr [[J]], align 4
// SIMD-ONLY0-NEXT:    [[TMP1:%.*]] = load i32, ptr [[MP_ADDR]], align 4
// SIMD-ONLY0-NEXT:    [[CMP:%.*]] = icmp slt i32 [[TMP0]], [[TMP1]]
// SIMD-ONLY0-NEXT:    br i1 [[CMP]], label [[FOR_BODY:%.*]], label [[FOR_END12:%.*]]
// SIMD-ONLY0:       for.body:
// SIMD-ONLY0-NEXT:    [[TMP2:%.*]] = load i32, ptr [[J]], align 4
// SIMD-ONLY0-NEXT:    store i32 [[TMP2]], ptr [[I]], align 4
// SIMD-ONLY0-NEXT:    br label [[FOR_COND1:%.*]]
// SIMD-ONLY0:       for.cond1:
// SIMD-ONLY0-NEXT:    [[TMP3:%.*]] = load i32, ptr [[I]], align 4
// SIMD-ONLY0-NEXT:    [[TMP4:%.*]] = load i32, ptr [[MP_ADDR]], align 4
// SIMD-ONLY0-NEXT:    [[CMP2:%.*]] = icmp slt i32 [[TMP3]], [[TMP4]]
// SIMD-ONLY0-NEXT:    br i1 [[CMP2]], label [[FOR_BODY3:%.*]], label [[FOR_END9:%.*]]
// SIMD-ONLY0:       for.body3:
// SIMD-ONLY0-NEXT:    store i32 0, ptr [[I0]], align 4
// SIMD-ONLY0-NEXT:    br label [[FOR_COND4:%.*]]
// SIMD-ONLY0:       for.cond4:
// SIMD-ONLY0-NEXT:    [[TMP5:%.*]] = load i32, ptr [[I0]], align 4
// SIMD-ONLY0-NEXT:    [[CMP5:%.*]] = icmp slt i32 [[TMP5]], 10
// SIMD-ONLY0-NEXT:    br i1 [[CMP5]], label [[FOR_BODY6:%.*]], label [[FOR_END:%.*]]
// SIMD-ONLY0:       for.body6:
// SIMD-ONLY0-NEXT:    br label [[FOR_INC:%.*]]
// SIMD-ONLY0:       for.inc:
// SIMD-ONLY0-NEXT:    [[TMP6:%.*]] = load i32, ptr [[I0]], align 4
// SIMD-ONLY0-NEXT:    [[INC:%.*]] = add nsw i32 [[TMP6]], 1
// SIMD-ONLY0-NEXT:    store i32 [[INC]], ptr [[I0]], align 4
// SIMD-ONLY0-NEXT:    br label [[FOR_COND4]], !llvm.loop [[LOOP2:![0-9]+]]
// SIMD-ONLY0:       for.end:
// SIMD-ONLY0-NEXT:    br label [[FOR_INC7:%.*]]
// SIMD-ONLY0:       for.inc7:
// SIMD-ONLY0-NEXT:    [[TMP7:%.*]] = load i32, ptr [[I]], align 4
// SIMD-ONLY0-NEXT:    [[INC8:%.*]] = add nsw i32 [[TMP7]], 1
// SIMD-ONLY0-NEXT:    store i32 [[INC8]], ptr [[I]], align 4
// SIMD-ONLY0-NEXT:    br label [[FOR_COND1]], !llvm.loop [[LOOP4:![0-9]+]]
// SIMD-ONLY0:       for.end9:
// SIMD-ONLY0-NEXT:    br label [[FOR_INC10:%.*]]
// SIMD-ONLY0:       for.inc10:
// SIMD-ONLY0-NEXT:    [[TMP8:%.*]] = load i32, ptr [[J]], align 4
// SIMD-ONLY0-NEXT:    [[INC11:%.*]] = add nsw i32 [[TMP8]], 1
// SIMD-ONLY0-NEXT:    store i32 [[INC11]], ptr [[J]], align 4
// SIMD-ONLY0-NEXT:    br label [[FOR_COND]], !llvm.loop [[LOOP5:![0-9]+]]
// SIMD-ONLY0:       for.end12:
// SIMD-ONLY0-NEXT:    ret void
//