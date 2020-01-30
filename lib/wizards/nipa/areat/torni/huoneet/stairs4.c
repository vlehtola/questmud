inherit "room/room";
object hefa;

reset(arg) {
  if(arg) return;
   
   if(!hefa) {
      hefa = clone_object("/wizards/nipa/areat/torni/mosat/hefasto.c");
      move_object(hefa, this_object()); }

    add_exit("down","stairs3.c");

   short_desc = "Huipulla tuulee, terv. Hugo";
    long_desc = "Huimaa näin korkealla.\n";
               
        set_light(3);
}
