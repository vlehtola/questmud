cmd_event_crain(arg) {
object list;
int i,o;

if(!arg || sscanf(arg, "%d", i) != 1) return;

//shout(this_player()->query_name()+" claps 

list = users();

for(o=0;o<sizeof(list);o++)     { 
  if((list[o]->query_wiz()==0) 
     && (list[o]->query_name=="Naltesttwo"))    
                                        {

tell_object(list[o],"test\n");
                                        }
                        }

write("loppu.\n");
return 1;
}
