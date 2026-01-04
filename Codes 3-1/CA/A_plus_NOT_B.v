// Module definition for A + NOT(B)
module A_plus_NOT_B(
    input wire A,      // Input A
    input wire B,      // Input B
    output wire Y      // Output Y
);

    // Implement the expression A + NOT(B)
    assign Y = A | ~B;

endmodule
