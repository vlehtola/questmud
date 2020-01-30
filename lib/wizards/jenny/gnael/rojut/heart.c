inherit "obj/armour";

start() 
{
   set_class(1);
   set_name("heart");
   set_short("A fresh looking human heart");
   set_long("A fresh looking human heart, it is still\n"+
            "covered with blood and it looks extremely\n"+
            "disgusting");
}


drop(arg) 
{
  object ob; 
  ob = environment(environment(this_object())); 

  if(!ob->heart_location()) return 0;

  tell_room(ob, "Mondasa calmly walks into the room\n"+
                "Mondasa says: 'So you are the ones that won my minions?'\n"+
                "Mondasa says: 'Well it doesn't matter anymore, NO ONE CAN EVER BEAT ME FOOLS!'\n");
  move_object(clone_object("/wizards/jenny/gnael/mosut/mondasa.c"), ob);
  this_player()->set_quest("The final battle begins");

  call_out("delay_dest", 1, this_object());

//  return 1;
}

int delay_dest(object ob) { destruct(ob); } // Oneliner for the call_out
