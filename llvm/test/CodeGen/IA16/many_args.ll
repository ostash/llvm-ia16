; RUN: llc -march=ia16 < %s | FileCheck %s

define i16 @many_args(i16 %a, i16 %b, i16 %c, i16 %d) {
; CHECK-LABEL: many_args:
; CHECK:       ; %bb.0:
; CHECK-NEXT:    add ax, bx
; CHECK-NEXT:    add ax, cx
; CHECK-NEXT:    add ax, dx
; CHECK-NEXT:    ret
entry:
  %add1 = add i16 %a, %b
  %add2 = add i16 %add1, %c
  %add3 = add i16 %add2, %d
  ret i16 %add3
}
