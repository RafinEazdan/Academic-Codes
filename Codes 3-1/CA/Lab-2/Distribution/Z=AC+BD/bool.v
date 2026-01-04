module bull(
    input a,
    input b,
    input c,
    input d,
    output z
);
wire p,q;
and(p,a,c);
and(q,b,d);
or(z,p,q);
endmodule