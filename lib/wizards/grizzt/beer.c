short() { return "A bottle of beer (labeled 'Porin Karhu')"; }

long() {
  write("Kesytt�m�t�n Karhu, lajinsa vahvin.\n");
  write("Korkkaa huurteisen kylm�n� ja nauti \n");
  write("Karhun t�ytel�isesta mausta. \n");
  write("Karhu on t�ytt� olutta. \n");
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

