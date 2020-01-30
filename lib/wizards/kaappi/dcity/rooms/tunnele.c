inherit "room/room";

reset(arg) {
if(arg) return;
 
  add_exit("tunnel", "t1.c");
  add_exit("northwest", "out: 196 50");
  add_exit("north", "out: 196 50");
  add_exit("northeast", "out: 196 50");
  add_exit("east", "out: 196 50");
 
  short_desc = "Entrance to the Tunnels of Amaranthgard";
  long_desc = "This is a big entrance of a tunnel. You think that\n"+ 
              "you have explored the area here before, but this\n"+ 
              "part of the tunnel hasn't been there. The tunnel\n"+
              "begins here and it starts to lead downhill. Something\n"
              "shiny can be seen in the end of the tunnel. There\n"
              "is a huge boulder leaning against a rock.\n";


items = allocate(2);
  items[0] = "boulder";
  items[1] = "It is just as big as the opening of the tunnel.\n"+
             "You wonder how it has been moved aside.\n";

}
