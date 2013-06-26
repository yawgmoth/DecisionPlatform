extern "C" {

extern int getrand_(int*, int*, int*, int*);

}

class DecisionMaker
{ 
   private:
       static DecisionMaker* dm;
       int hist[4];
       int sf;
   public:
       int (*fp)();
       static DecisionMaker* instance() { return dm; }
       static void init(int smoothinfactor) { dm = new DecisionMaker; dm->sf = smoothinfactor; }
       DecisionMaker() {  for (int i = 0; i < 4; ++i) hist[i] = i%2; }
       int make_decision()
       {
           unsigned int fp1, fp2;
           memcpy((char*)&fp1, (char*)&fp, 4);
           if (sizeof(void*) > 4)
           { 
              memcpy((char*)&fp2, ((char*)&fp)+4, 4);
           }
           else
           {
              fp2 = 0;
           }
           return getrand_(hist, (int*)&fp1, (int*)&fp2, &sf);
       }

};