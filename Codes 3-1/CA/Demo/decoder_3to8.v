module decoder_3to8 (
    input [2:0] A,       // 3-bit input
    output reg [7:0] Y   // 8-bit output
);

    always @(*) begin
        case (A)
            3'b000: Y = 8'b00000001;  // Output 0 is active
            3'b001: Y = 8'b00000010;  // Output 1 is active
            3'b010: Y = 8'b00000100;  // Output 2 is active
            3'b011: Y = 8'b00001000;  // Output 3 is active
            3'b100: Y = 8'b00010000;  // Output 4 is active
            3'b101: Y = 8'b00100000;  // Output 5 is active
            3'b110: Y = 8'b01000000;  // Output 6 is active
            3'b111: Y = 8'b10000000;  // Output 7 is active
            default: Y = 8'b00000000; // Default case (shouldn't happen)
        endcase
    end

endmodule
