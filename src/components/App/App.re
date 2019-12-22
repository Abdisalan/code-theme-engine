[@react.component]
let make = () => {
  <div style={ReactDOMRe.Style.make(~margin="10px", ())}>
    <Preview />
    <Configuration />
  </div>;
};