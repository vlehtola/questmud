string short_desc;

short() { return short_desc; }

reset(arg) {
  if(arg) destruct(this_object());
  if(!short_desc) short_desc = "lambda";
  lambda(0, ({#',,
	({#'tell_object, this_player(), "jees\n" }),
	({#'=, 'short_desc, "jees" }),
  }) );
}

/*    set_driver_hook(
      H_MOVE_OBJECT0,
      unbound_lambda( ({'item, 'dest}), ({#',,
#ifdef NATIVE_MODE
        ({#'?, ({#'!=, 'item, ({#'this_object})}),
          ({#'raise_error,
            "Illegal to move other object than this_object()\n"}) }),
#endif
#ifdef COMPAT_FLAG
        ({#'&&, ({#'living, 'item}), ({#'environment, 'item}), ({#',,
          ({#'efun::set_this_player, 'item}),
          ({#'call_other, ({#'environment, 'item}), "exit", 'item}),
        }) }),
#endif
        ({#'efun::efun308, 'item, 'dest}),
        ({#'?, ({#'living, 'item}), ({#',,
          ({#'efun::set_this_player, 'item}),
          ({#'call_other, 'dest, "init"}),
          ({#'?, ({#'!=, ({#'environment, 'item}), 'dest}), ({#'return})}),
        }) }),
        ({#'=, 'others, ({#'all_inventory, 'dest}) }),
        ({#'=, ({#'[, 'others, ({#'member, 'others, 'item}) }), 0}),
        ({#'filter_array, 'others,

*/
