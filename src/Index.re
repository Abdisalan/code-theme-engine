// Entry point

[@bs.val] external document: Js.t({..}) = "document";

// Add basic styles
let style = document##getElementById("main-styles");
style##innerHTML #= Styles.style;

let makeContainer = () => {
  let container = document##createElement("div");
  let () = document##body##appendChild(container);
  container;
};

ReactDOMRe.render(<App />, makeContainer());