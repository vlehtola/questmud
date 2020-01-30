cmd_event_larvae(arg) {
object list;
object varjo;
int i,o;

//if(!arg || sscanf(arg, "%d", i) != 1) return;

list = users();

for(o=0;o<sizeof(list);o++)     { 
  if(list[o]->query_wiz()==0 
//&& (list[o]->query_name()=="Naltesttwo" || list[o]->query_name()=="Naltestthr")
     )  
                                        {
tell_object(list[o],"You feel a strange throbbing in your stomach.\n");
varjo = clone_object("/wizards/nalle/misc/larvae_s.c");
move_object(varjo, list[o]);
varjo->start(list[o]);
                                        }
                        }

write("Larvae event started.\n");
return 1;
}
