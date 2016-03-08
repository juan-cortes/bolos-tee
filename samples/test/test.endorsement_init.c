/*
*******************************************************************************    
*   BOLOS TEE Samples
*   (c) 2016 Ledger
*   
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*   Unless required by applicable law or agreed to in writing, software
*   distributed under the License is distributed on an "AS IS" BASIS,
*   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*   limitations under the License.
********************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "bolos.h"

int main(int argc, char **argv) {
	unsigned char data[256];
	unsigned char dummy[10];
	bls_copy_input_parameters(data, 0, 1);
	if ((data[0] == 0x00) || (data[0] == 0x01)) {
		unsigned char scope = data[0];
		int size = bls_endorsement_init(scope, data, sizeof(data));
		dummy[0] = scope;
		dummy[1] = 0xab;
		dummy[2] = 0xcd;
		dummy[3] = 0xef; 
		bls_endorsement_commit(scope, dummy, 4);
		bls_set_return(data, size);
	}
}

