class Robot {
public:
int x;
int y;
string dir;
int n;
int m;
    Robot(int width, int height) {
        x=0;
        y=0;
        dir="East";
        n=width;
        m=height;

    }
    
    void step(int num) {
        if(num==0)return ;
        int p=2*((n-1)+(m-1));
        if(num%p==0){
            if(x==0&&y==0){dir="South";}
            else if(x==0&&y==m-1){dir="West";}
            else if(x==n-1&&y==0){dir="East";}
            else if(x==n-1&&y==m-1){dir="North";}
        }
        num=num%p;

        //here this condition is wrong when step(0) then no movement but still here direction change 
        // if(num==0){
        //     dir="South";
        // }
        while(num>0){
            if(dir=="East"){
                if(x+num>=n){
                    int a=n-x-1;
                    x=n-1;
                    num-=a;
                    dir="North";
                }
                else{
                    x+=num;
                    break;
                }
            }
            else if(dir=="North"){
                if(y+num>=m){
                    int a=m-y-1;
                    y=m-1;
                    num-=a;
                    dir="West";
                }
                else{
                    y+=num;
                    
                    break;
                }
            }
            else if(dir=="West"){
                if(x-num<0){
                   
                    num-=x;
                     x=0;
                     dir="South";
                }
                else{
                    x-=num;
                    break;
                }
            }
            else{
                if(y-num<0){
                    num-=y;
                    y=0;
                    dir="East";
                }
                else{
                    y-=num;
                    break;
                }
            }
            
        }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        return dir;
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */