`timescale 1ns/1ns

module tb_left_rotate_4bit;

    reg [3:0] A;          // 4-bit input operand
    wire [3:0] Y;         // 4-bit rotated output

    left_rotate_4bit uut (
        .A(A),
        .Y(Y)
    );

    initial begin
        $dumpfile("test.vcd");
        $dumpvars(0, tb_left_rotate_4bit);

        
        A = 4'b1001; #10; // Test with input 1001
        A = 4'b1100; #10; // Test with input 1100
        A = 4'b0111; #10; // Test with input 0111
        A = 4'b0001; #10; // Test with input 0001
        $finish;
    end

    
    initial begin
        $monitor("Time = %0t | A = %b | Y = %b", $time, A, Y);
    end

endmodule
