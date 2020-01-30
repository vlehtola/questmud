/*
 * Made By Garath / 19.09.02
 */
 
mapping visited;
 
#define QUEST_NAME "Exploration schaisse"
#define AMOUNT 10
 
void reset(status x) {
  if(x) return;
  visited = ([]);
}
 
void check_rooms(object room) {
  object player;
  string tmp;
 
  player = this_player();
  tmp = player->query_real_name();
  if(visited[tmp]) {                
   if(member_array(file_name(room),visited[tmp]) != -1) {
   visited[tmp] = visited[tmp] + ({ file_name(room), });
 }
} else {
  visited[tmp] = ({ file_name(room), });
}


  if(sizeof(visited[tmp]) >= AMOUNT) {
    player->set_quest(QUEST_NAME);
  }
}
 
mapping query_visited() {
  return visited;
}
 
void reset_visited() {
  visited = ([]);
}
