inherit "obj/armour";

start() 
{
   set_class(1);
   set_name("bone");
   set_short("A filthy looking human bone");
   set_long("A filty looking human bone which seems to be\n"+
            "pretty fresh. Maybe some troll hid it there for later\n"+
            "use.\n");
}


drop(arg) 
{
  object ob; 
  ob = environment(environment(this_object())); 

  if(!ob->bone_location()) return 0;

  tell_room(ob, "An angry troll appears from the shadows and takes the bone.");

  tell_room(ob, "Troll roars: You mean people have stolen my bone!'\n"+
                "Troll continues: 'I will kill you for that!'\n");
  move_object(clone_object("/wizards/jenny/mehta/mosut/troll.c"), ob);
  this_player()->set_quest("Find the angry troll");

  call_out("delay_dest", 1, this_object());

//  return 1;
}


int delay_dest(object ob) { destruct(ob); } // Oneliner for the call_out
