`timescale 1ns/1ns

module tb_A_plus_NOT_B;
    reg A;
    reg B;
    wire Y;

    // Instantiate the module under test
    A_plus_NOT_B uut (
        .A(A),
        .B(B),
        .Y(Y)
    );

    // Generate a test clock signal
    initial begin
        // Open a VCD file for waveform viewing
        $dumpfile("test.vcd");
        $dumpvars(0, tb_A_plus_NOT_B);

        // Initialize inputs
        A = 0;
        B = 0;

        // Apply test cases
        #10 A = 0; B = 0; // Test case 1
        #10 A = 0; B = 1; // Test case 2
        #10 A = 1; B = 0; // Test case 3
        #10 A = 1; B = 1; // Test case 4

        // Finish simulation
        $finish;
    end

    // Monitor signals
    initial begin
        $monitor(" A = %b, B = %b, Y = %b", $time, A, B, Y);
    end

endmodule
