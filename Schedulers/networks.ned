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

package tirtproject.Schedulers;
import tirtproject.Generators.*;

simple Scheduler
{
    parameters:
    	volatile double delay @unit(s) = default(exponential(1s));
    
    @display("i=device/accesspoint"); 
    gates:
        input in[];
        output out;        
}

network SCHFifo {

    submodules:
        OnOff: OnOffGenerator {
        	@display("p=50,50");
        };
        
        poissonGenerator: PoissonGenerator {
        	@display("p=50,150");
        };
        
        MMPPGenerator: MMPPGenerator {
        	@display("p=50,250");
        };        
        
        SCH : FIFOScheduler {
        	@display("p=150,150");
        };
        
        sink: Node {
        	@display("p=250,150");
        };
        
    connections:
        
        OnOff.out --> SCH.in++;
        poissonGenerator.out --> SCH.in++;
        MMPPGenerator.out --> SCH.in++;
        SCH.out --> sink.in;
        
}


network SCHLifo {

    submodules:
        OnOff: OnOffGenerator {
        	@display("p=50,50");
        };
        
        poissonGenerator: PoissonGenerator {
        	@display("p=50,150");
        };
        
        MMPPGenerator: MMPPGenerator {
        	@display("p=50,250");
        };        
        
        SCH : LIFOScheduler {
        	@display("p=150,150");
        };
        
        sink: Node {
        	@display("p=250,150");
        };
        
    connections:
        
        OnOff.out --> SCH.in++;
        poissonGenerator.out --> SCH.in++;
        MMPPGenerator.out --> SCH.in++;
        SCH.out --> sink.in;
        
}


network SCHRR {

    submodules:
        OnOff: OnOffGenerator {
        	@display("p=50,50");
        };
        
        poissonGenerator: PoissonGenerator {
        	@display("p=50,150");
        };
        
        MMPPGenerator: MMPPGenerator {
        	@display("p=50,250");
        };        
        
        SCH : RRScheduler {
        	@display("p=150,150");
        };
        
        sink: Node {
        	@display("p=250,150");
        };
        
    connections:
        
        OnOff.out --> SCH.in++;
        poissonGenerator.out --> SCH.in++;
        MMPPGenerator.out --> SCH.in++;
        SCH.out --> sink.in;
        
}