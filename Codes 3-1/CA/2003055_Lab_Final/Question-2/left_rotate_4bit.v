module left_rotate_4bit (
    input [3:0] A,       // 4-bit input operand
    output [3:0] Y       // 4-bit rotated output
);

    assign Y = {A[2:0], A[3]}; // Left rotate operation

endmodule
