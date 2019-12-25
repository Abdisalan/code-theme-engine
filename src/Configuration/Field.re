[@react.component]
let make = (~label, ~value, ~onChange) => {
  <>
    <label> {React.string(label)} </label>
    <input type_="text" name=label onChange={onChange(label)} value />
  </>;
};