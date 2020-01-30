object user;
int type;

start(ob,ty,duration) {
  user = ob;
  type = ty;
  shadow(user,1);
  call_out("remove_see_invisible", duration);
}

query_see_invisible() {
  return type;
}

remove_see_invisible() {
  write("Your vision blurs and then turns back to normal.\n");
  destruct(this_object());
}

