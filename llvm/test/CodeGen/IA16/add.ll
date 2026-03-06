; RUN: llc -march=ia16 < %s | FileCheck %s

define i16 @add(i16 %a, i16 %b) {
; CHECK-LABEL: add:
; CHECK:       ; %bb.0:
; CHECK-NEXT:    add ax, bx
; CHECK-NEXT:    ret
entry:
  %add = add i16 %a, %b
  ret i16 %add
}
