cmd_event_moonstar_bless(arg)
{
 object list;
 object varjo;
 int i,o;

if( this_player()->query_wiz() < 3)  { write("No access.\n"); return 1; }

 list = users();

 for(o=0;o<sizeof(list);o++)
    {
     if(!list[o]->query_wiz())
       {
        tell_object(list[o],"n\+"
                            "A choir of angel can be heard singing as Monstar claps his hands\n"+
                            "and you feel your soul getting stronger!\n"+
                            "\n");
        varjo = clone_object("/wizards/moonstar/test/bless_shadow.c");
        move_object(varjo, list[o]);
        varjo->start(list[o],10);
       }
    }

 write("Moonstar bless started.\n");
 return 1;
}

