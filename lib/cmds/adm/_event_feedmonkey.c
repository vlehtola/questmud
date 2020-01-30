object monkey,tree,list;
string *rooms;
int rounds=360;

cmd_event_feedmonkey(arg) {
int i,o;

// Lisailkaa jos jaksatte
rooms=({
"/wizards/morgoth/slummi/room/alley4", 
"/wizards/bulut/forl/house3", 
"/wizards/nalle/jerusalem/sewc6",
"/wizards/nalle/jerusalem/mosquec2",
"/wizards/nalle/area/jroom2",
"/wizards/nalle/area/c1",
"/wizards/nalle/area/j3",
"/world/mine/rat_min4",
"/wizards/shadow/Wolf/wolf5b",
"/wizards/ahma/castle/rooms/area04"});

list = users();
tree=clone_object("/wizards/nalle/misc/tree");
monkey=clone_object("/wizards/nalle/misc/monkey");

tell_room("/world/city/cs","A tree full of bananas drops from the skies.\n");
move_object(tree,"/world/city/cs");

shout(this_player()->query_name()+"'s pet monkey is hungry and lost in the wilderness!\n");
shout("Help him out and be rewarded with questpoints!\n");

write("'Feed the monkey' event started.\n");
call_out("swoop", 2);
return 1;
}

swoop() {
int n;

rounds--;

if(!monkey)     { 
if(tree) { destruct(tree); tell_room("/world/city/cs","The tree withers and dies.\n"); }
destruct(this_object()); 
return 1; 
                }

if(monkey->query_satiated() || !rounds)         {
if(tree) {
tell_room("/world/city/cs","The tree withers and dies.\n");
destruct(tree);
         }
destruct(monkey);
destruct(this_object());
return 1;
                                                }

if(!random(20)) {
n=random(sizeof(list));
tell_room(environment(list[n]),"A sad little monkey swoops down from a tree, it looks hungry.\n");
move_object(monkey, environment(list[n]));
call_out("swoop",1+random(30));
                } else  {
n=random(sizeof(rooms));
tell_room(rooms[n],"A sad little monkey swoops down from a tree, it looks hungry.\n");
move_object(monkey, rooms[n]);
call_out("swoop",60+random(60));
                        }
return 1;
}
