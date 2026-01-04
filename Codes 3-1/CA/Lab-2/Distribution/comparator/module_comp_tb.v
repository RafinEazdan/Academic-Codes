`timescale 1ns/1ps
module comparator_tb;
reg x;
reg y;
wire z;
comparator uut(
    .x(x),
    .y(y),
    .z(z)
);
initial begin
    $dumpfile("test.vcd");
    $dumpvars(0, comparator_tb);
    x=0;y=0;
    #20
    x=1;y=0;
    #20
    x=1;y=1;
    #20
    x=0;y=1;
end
initial begin
$monitor("x = %d, y = %d, z = %d \n",x,y,z);
end
endmodule