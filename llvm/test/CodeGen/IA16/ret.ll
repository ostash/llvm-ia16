; RUN: llc -march=ia16 < %s | FileCheck %s

define i16 @get_const() {
; CHECK-LABEL: get_const:
; CHECK:       ; %bb.0:
; CHECK-NEXT:    mov ax, 42
; CHECK-NEXT:    ret
entry:
  ret i16 42
}

define i16 @pass_through(i16 %a) {
; CHECK-LABEL: pass_through:
; CHECK:       ; %bb.0:
; CHECK-NEXT:    ret
entry:
  ret i16 %a
}
