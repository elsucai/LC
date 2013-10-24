class Solution {
	public:
		int singleNumber(int A[], int n) {
			// Note: The Solution object is instantiated only once and is reused by each test case.
			
			// each bit in the 3-appearance number appear 3 times also
			// ones holds all the bits that appear exactly 1 time
			// twos holds all the bits that appear exactly 2 times
			// clear all bits in ones & twos, which appear 3 times and should be deleted 
			

			int ones = 0, twos = 0 ;
			int common_bit_mask;

			for( int i = 0; i < n; i++){
				// ones & A[i] get thoses bits in A[i] that appear 2 times
				// and add them to twos
				twos  = twos | (ones & A[i]);

				// add those bits in A[i] which appears first time to ones
				ones  = ones ^ A[i];

				// find those bits appear exactly 3 times, and construct common_bit_mask accordingly
				common_bit_mask = ~(ones & twos);

				// Remove common bits (the bits that appear third time) from 'ones' and 'twos'
				ones &= common_bit_mask;
				twos &= common_bit_mask;
			}

			return ones;
		}
};
