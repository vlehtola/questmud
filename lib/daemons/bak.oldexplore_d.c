// Testing by Nalle -- Apr 03

#define TP this_player()

/*****************************************/

int add_room(object player)
{
 string envpath,tmp;
 int x,y;

 if(!player) player=TP;
 if(player->query_npc()) return 1; // Check its a player
 return 1;

 envpath=file_name( environment(player) );
 if(!envpath) return 0;

 // no explore for virtual rooms
 if(!environment(player)->query_room_file()) return 1;

 if(sscanf(envpath,"%s: %d %d",tmp,x,y) == 3) 
 {
  return 1;
 }

 player->set_explored( crypt( envpath , "aa" )[0..5] );
 return 2;
}

/*****************************************/

int explored_rooms(object player)
{
int amount;

if(!player) player=TP;
amount= sizeof( m_indices( player->query_explored() ) );
return amount;
}

/*****************************************/

