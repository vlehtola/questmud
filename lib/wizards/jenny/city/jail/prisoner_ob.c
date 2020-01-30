object vanki;

start(ob) {
  vanki = ob;
  shadow(vanki, 1);
  return 1;
}

short() {
        return vanki->short()+" (in jail)";
}

vapaudu() {
  destruct(this_object());
}
