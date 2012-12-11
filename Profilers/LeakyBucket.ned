package tirtproject.Profilers;

simple LeakyBucket
{
    parameters:
        volatile double serviceTime @unit(s);
        volatile int buffer;
        @display("i=block/bucket,#0080C0");
    gates:
        input in;
        output out;
}
