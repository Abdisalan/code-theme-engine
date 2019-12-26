[@react.component]
let make = (~label, ~value, ~onChange) => {
  let hexValidation = (hex: string): bool => {
    let r =
      Js.Re.fromStringWithFlags("^#([0-9a-f]{3}|[0-9a-f]{6})$", ~flags="i");
    Js.Re.test_(r, hex);
  };

  let (style, setStyle) = React.useState(() => ReactDOMRe.Style.make());

  React.useEffect1(
    () => {
      let () =
        if (hexValidation(value)) {
          setStyle(_ => ReactDOMRe.Style.make());
        } else {
          setStyle(_ => ReactDOMRe.Style.make(~borderColor="red", ()));
        };
      None;
    },
    [|value|],
  );

  <div className="field-container">
    <div
      className="colorBlock"
      style={ReactDOMRe.Style.make(~background=value, ())}
    />
    <div className="field">
      <label> {React.string(label)} </label>
      <input type_="text" name=label onChange={onChange(label)} value style />
    </div>
  </div>;
};