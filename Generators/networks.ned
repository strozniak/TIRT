//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package tirtproject.Generators;

simple PoissonGenerator
{
    parameters:
        @display("i=block/source");
        double lambda = default(0.5);
        int rnb = default(0);
    gates:
    	output out;        
}

simple OnOffGenerator
{
    parameters:
        volatile double delayTime @unit(s) = default(exponential(1s));
        volatile int destNumber = default(10);
        volatile int classNumber = default(5);
        volatile int sessionId = default(10);
        volatile int packetId  = default(10);
        
        volatile int changeValue  = default(50);
        volatile int lowerBound  = default(0);
        volatile int upperBound  = default(100);
        
        volatile int OnOff = default(1);
                
        @display("i=block/source");
    gates:
        output out;
}

simple MMPPGenerator
{
    parameters:
        @display("i=block/source");
        double lambda = default(0.5);
        int rnb = default(0);
    gates:
    	output out;     
}

simple Node
{
    parameters:
        @display("i=block/sink");
        gates:
        	input in;
}

network PoissonGeneratorNetwork
{
    submodules:
        poissonGenerator: PoissonGenerator;
        sink: Node;
        
        connections:
            poissonGenerator.out --> sink.in;
}

network OnOffNetwork
{
    submodules:
        OnOff: OnOffGenerator;
        sink: Node;
    connections:
        OnOff.out --> sink.in;
}

network MMPPNetwork
{
    submodules:
        mmppGenerator: MMPPGenerator;
        sink: Node;
        
        connections:
            mmppGenerator.out --> sink.in;
}