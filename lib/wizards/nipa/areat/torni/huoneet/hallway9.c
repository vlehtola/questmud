
inherit "room/room";
inherit "room/door";

 reset(arg) 
   {
        add_exit("northwest", "hallway8.c");        
        add_exit("southwest", "hallway10.c");

   short_desc = "Descii uupuu.\n";
   long_desc = ("Desci uupuu.\n"+
               "Keksitaan jotain joskus, teen vaan pohjan mallin valmiiks.\n");  
 set_light(2);
 
 door_reset();
set_door_label("wooden door",1);
set_door_dir("east", "koppi5.c",1);
set_door_link("/wizards/nipa/areat/torni/huoneet/koppi5.c",1);
set_locked(0, 1);

 set_not_out();
}
            
 init() {
     ::init();
     door_init();
}