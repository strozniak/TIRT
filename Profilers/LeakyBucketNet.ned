package tirtproject.Profilers;

import tirtproject.Generators.*;


network LeakyBucketNet
{
    submodules:
        gen: PoissonGenerator;
        bucket: LeakyBucket;
        sink: Node;
    connections:
        gen.out --> bucket.in;
        bucket.out --> sink.in;
}
