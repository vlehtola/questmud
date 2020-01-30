object user; /* the one we shadow */

/* call start with an object as an argument */
start(ob) {
  user = ob;
  shadow(user, 1); /* start the shadowing */
}

/* this is called when user's short is called */
short() {
  if(random(2)==0) return "This is the other short";
  return user->short(); /* call the original short */
}

update_stats() {
  user->update_stats();
  user->set_str(1); /* nice, isn't it */
}

/* for every function that you declare here and that exists in shadowed object */
/* the lpc driver will call the function of this object, not the one in the object */
/* NOTE: shadowing query_level() query_wiz() query_real_name() etc. is not worth trying */
/* 1. It's impossible 2. I'll mad to you             //Celtron */
