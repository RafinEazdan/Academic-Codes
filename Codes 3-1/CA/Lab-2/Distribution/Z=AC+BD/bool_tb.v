`timescale 1ns/1ps
module bull_tb;
reg a;
reg b;
reg c;
reg d;
wire z;
bull uut(
    .a(a),
    .b(b),
    .c(c),
    .d(d),
    .z(z)
);
initial begin
    $dumpfile("test.vcd");
    $dumpvars(0,bull_tb);
    a = 0; b=0;c=0;d=0;
    #20
    a=0;b=1;c=0;d=1;
    #20
    a=0;b=1;c=1;d=0;
    #20
    a=0;b=1;c=0;d=0;
    #20
    a=1;b=1;c=1;d=1;
end
initial begin
$monitor("a = %d,b = %d, c = %d, d = %d, z = %d \n",a,b,c,d,z);
end
endmodule
