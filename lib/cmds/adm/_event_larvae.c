cmd_event_larvae(arg) 
{
 object list;
 object varjo;
 int i,o;

 if( TP->query_wiz() < 4) { write("No access.\n"); return 1; }

 list = users();

 for(o=0;o<sizeof(list);o++)
    {
     if(!list[o]->query_wiz())
       {
        tell_object(list[o],"A sporal cloud fills the skies, arriving from the eastern wastelands.\n");
        varjo = clone_object("/wizards/nalle/misc/larvae_s.c");
        move_object(varjo, list[o]);
        varjo->start(list[o]);
       }
    }

 write("Larvae event started.\n");
 return 1;
}
