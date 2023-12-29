#ifndef RRIP_REPL_H_
#define RRIP_REPL_H_

#include "repl_policies.h"

class SRRIPolicy : public ReplPolicy {
    protected:
        uint64_t* array;
        uint32_t numLines;
        uint32_t just_replaced_now;
        uint32_t maxValue;
	
    public:
        explicit SRRIPolicy(uint32_t _numLines,uint32_t _maxValue) : numLines(_numLines),maxValue(_maxValue) {
            array = gm_calloc<uint64_t>(numLines);
	    for(uint32_t i = 0;i < numLines ; i++)
		cout << array[i];
        }

        ~SRRIPolicy() {
            gm_free(array);
        }

	
        void update(uint32_t id, const MemReq* req) {
            if(just_replaced_now != 1)
		array[id] = 0;
	    else
		just_replaced_now = 0;
        }

	void replaced(uint32_t id) {
            array[id] = maxValue -1;
		just_replaced_now = 1;
        }

	template <typename C> inline uint32_t rank(const MemReq* req, C cands) {
            uint32_t bestCand = -1;
            uint64_t bestScore = maxValue;
	    while (bestCand == -1)
	    {
	       for (auto ci = cands.begin(); ci != cands.end(); ci.inc()) {
                uint32_t s = array[*ci];
		if(s == bestScore)
		  bestCand = *ci;
              }
	     if(bestCand == -1){
		
	       for (auto ci = cands.begin(); ci != cands.end(); ci.inc()) 
		array[*ci]++;

		
		}
	 else
		break;
 
	    }
            
            return bestCand;
        }


        DECL_RANK_BINDINGS;
 };
#endif      
