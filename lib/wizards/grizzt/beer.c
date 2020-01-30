short() { return "A bottle of beer (labeled 'Porin Karhu')"; }

long() {
  write("Kesyttämätön Karhu, lajinsa vahvin.\n");
  write("Korkkaa huurteisen kylmänä ja nauti \n");
  write("Karhun täyteläisesta mausta. \n");
  write("Karhu on täyttä olutta. \n");
  }

get() { return 1; }

drop() { return 0; }

id(str) { return str == "beer"; }

init() {
  add_action("juo", "drink");
}

juo(str) {
  if(str != "beer" && str != "beer") { return; }
  write("AAAAh, that feels good.\n");
  this_player()->drink_soft(10000);
  destruct(this_object());
  return 1;
}

