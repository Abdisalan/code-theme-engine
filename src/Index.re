// Entry point

[@bs.val] external document: Js.t({..}) = "document";

// Add styles
let style = document##createElement("style");
document##head##appendChild(style);
style##innerHTML #= Theme.createTheme(ThemeTemplate.default);

let makeContainer = () => {
  let container = document##createElement("div");
  let () = document##body##appendChild(container);
  container;
};

ReactDOMRe.render(<App />, makeContainer());