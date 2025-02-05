The `tilt` gem no longer supports `erubis` for templating. Use `erubi` instead.

Issue: `erubis` hasn't been supported in over 10 years, so it has been removed
as a template engine for the `tilt` gem.

If you get the error message
    ` ... 'require' cannot load such file -- tilt/erubis (LoadError)`
when running a Sinatra app (maybe suddenly and out of the blue even though
things were working perfectly fine just a few hours ago), it's because of this
removal.

Solution: use the `erubi` (no trailing 's') library instead. You may need to
install the `erubi` gem, but otherwise seems to be a smooth swap.
- Ekerin
