# Data_Structure_project2
一些初步的想法，大家clone之后随意修改，然后上传就好     

### 飞机和跑道类问题应该不大，机场类还要和大佬继续商量
### Tips.  
true->take off  
false->land

## 目前的流程
### Previous:  
1.Set Takeoff & Land queues.  
2.Set runways.(which means the numbers of planes that can be processed in one time)  
Tip.Land & Takeoff would take 1 time, ignoring the time for putting planes into Takeoff & Land queues.  
### Current:  
1.Message: 1 plane will be put into some queue.  
void Message(Plane newPlane);

2.Order: Update all planes' state.  
void Order();

3.Take_Land: Pop the planes into runways.  
vector<Plane> Take_Land();

4.Request: return:whether there is a plane crashed, the condition of planes in runways.  


5.Show: both of the whole queues.  
### After:  
...
