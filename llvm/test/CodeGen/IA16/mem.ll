; RUN: llc -march=ia16 < %s | FileCheck %s

define i16 @load_add_store(ptr %p, i16 %val) {
; CHECK-LABEL: load_add_store:
; CHECK:       ; %bb.0:
; CHECK-NEXT:    mov cx, [ax]
; CHECK-NEXT:    add cx, bx
; CHECK-NEXT:    mov [ax], cx
; CHECK-NEXT:    mov ax, cx
; CHECK-NEXT:    ret
entry:
  %v1 = load i16, ptr %p
  %v2 = add i16 %v1, %val
  store i16 %v2, ptr %p
  ret i16 %v2
}
