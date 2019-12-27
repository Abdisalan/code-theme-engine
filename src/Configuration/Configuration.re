[@bs.val] external document: Js.t({..}) = "document";

[@react.component]
let make = () => {
  let (theme, setTheme) = React.useState(() => Theme.default);

  React.useEffect1(
    () => {
      let style = document##getElementById("prism-styles");
      style##innerHTML #= Theme.createTheme(theme);
      None;
    },
    [|theme|],
  );

  let download: string => unit = [%bs.raw
    {|
    function(theme) {
      var fileName = "theme.css";
      var content = new Blob([theme], {type: "text/plain"});
      document.getElementById("download").setAttribute("href", window.URL.createObjectURL(content));
      document.getElementById("download").setAttribute("download", fileName);
    }
  |}
  ];

  // Prepare Download link
  React.useEffect1(
    () => {
      let fileContent = Theme.createTheme(theme);
      download(fileContent);
      None;
    },
    [|theme|],
  );

  let onChange = (name: string, e) => {
    switch (
      e |> ReactEvent.Form.target |> Js.Nullable.return |> Js.Nullable.toOption
    ) {
    | None => ()
    | Some(target) =>
      setTheme(_ => Theme.updateTheme(name, target##value, theme))
    };
  };

  let fields = [|
    ("background", theme.background),
    ("comment", theme.comment),
    ("string", theme.string),
    ("keyword", theme.keyword),
    ("language", theme.language),
    ("punctuation", theme.punctuation),
    ("function", theme.function_),
    ("operator", theme.operator),
    ("highlight", theme.highlight),
    ("highlightBorder", theme.highlightBorder),
    ("tag", theme.tag),
    ("property", theme.property),
  |];

  let transform = args =>
    switch (args) {
    | (field, value) => <Field key=field label=field value onChange />
    };

  <div className="config">
    <form> {ReasonReact.array(Array.map(transform, fields))} </form>
    <a href="" id="download"> {React.string("Export")} </a>
  </div>;
};