cmd_event_cbandit(arg) {
object list;
object suklaa, banditti, env;
int i,o;
string tmp, temppi;

//if(!arg || sscanf(arg, "%d", i) != 1) return;

list = users();

for(o=0;o<sizeof(list);o++)     { 
  if(list[o]->query_wiz()==0 
// && (list[o]->query_name()=="Naltesttwo" || list[o]->query_name()=="Naltestthr")
     )  {

env=environment(list[o]);

if((sscanf(file_name(env), "/world/city/i%s", tmp))
|| (sscanf(file_name(env), "/world/shops/%s", tmp))
|| (sscanf(file_name(env), "/guilds/%s", tmp))
|| (file_name(env)=="/room/bank")
|| (file_name(env)=="/room/locker")
  ) { } else {

tell_object(list[o],"A shapely elven bandit arrives in a puff of smoke.\n");
tell_object(list[o],"The female bandit hands you a bar of chocolate, what a nice thing to do!\n");
suklaa = clone_object("/wizards/nalle/misc/chocolate.c");
banditti = clone_object("/wizards/nalle/misc/cbandit.c");
move_object(suklaa, list[o]);

banditti->set_short("A cute female bandit, thinking about "+list[o]->query_name());
move_object(banditti, environment(list[o]));
banditti->set_master(list[o]);
                                        } }
                        }

write("'Chocolate bandits' event started.\n");
return 1;
}
