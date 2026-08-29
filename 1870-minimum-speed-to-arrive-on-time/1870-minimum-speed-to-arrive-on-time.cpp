class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
      int low = 1;
      int high = 10000000;
      int ans = -1;
      while(low <= high){
        int mid = low + (high-low)/2;
        double totaltime = 0;
        int time = 0;
        double lastTime = 0;
        for (int i = 0;i<dist.size();i++){
            if(i != dist.size()-1){
                time = (dist[i] + mid - 1) / mid;
                totaltime += time;
            }
            else{
                double lastTime = (double)dist[i]/mid;
                totaltime += lastTime;
            }
        }
        if (totaltime <= hour){
            ans = mid;
            high = mid-1;
        }
        else {
            low = mid+1;
        }
      } 
      return ans; 
    }
};