`timescale 1ns/1ns

module tb_decoder_3to8;

    reg [2:0] A;          // 3-bit input
    wire [7:0] Y;         // 8-bit output

    // Instantiate the 3-to-8 decoder
    decoder_3to8 uut (
        .A(A),
        .Y(Y)
    );

    initial begin
        // Open VCD file for waveform analysis
        $dumpfile("test.vcd");
        $dumpvars(0, tb_decoder_3to8);

        // Apply test cases
        A = 3'b000; #10; // Test input 0
        A = 3'b001; #10; // Test input 1
        A = 3'b010; #10; // Test input 2
        A = 3'b011; #10; // Test input 3
        A = 3'b100; #10; // Test input 4
        A = 3'b101; #10; // Test input 5
        A = 3'b110; #10; // Test input 6
        A = 3'b111; #10; // Test input 7

        // End simulation
        $finish;
    end

    // Monitor the inputs and outputs
    initial begin
        $monitor("Time = %0t | A = %b | Y = %b", $time, A, Y);
    end

endmodule
