[@bs.val] external document: Js.t({..}) = "document";

[@react.component]
let make = () => {
  let (theme, setTheme) = React.useState(() => Theme.default);

  React.useEffect1(
    () => {
      let style = document##createElement("style");
      let () = document##head##appendChild(style);
      style##innerHTML #= Theme.createTheme(theme);
      Some(() => document##head##innerHTML #= "");
    },
    [|theme|],
  );

  let download: string => unit = [%bs.raw
    {|
    function(theme) {
      var fileName = "theme.css";
      var content = new Blob([theme], {type: "text/plain"});
      console.log(content);
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
    // e->ReactEvent.Form.target->Js.Nullable.return->Js.Nullable.toOption
    switch (
      e |> ReactEvent.Form.target |> Js.Nullable.return |> Js.Nullable.toOption
    ) {
    | None => Js.log("this bih null")
    | Some(target) =>
      Js.log("we got some" ++ target##value);
      setTheme(_ => Theme.updateTheme(name, target##value, theme));
    };
  };

  <form>
    <label> {React.string("Comment")} </label>
    <input type_="text" name="comment" onChange={onChange("comment")} />
    <label> {React.string("String")} </label>
    <input type_="text" name="string" onChange={onChange("string")} />
    <label> {React.string("Selector")} </label>
    <input type_="text" name="selector" onChange={onChange("selector")} />
    <label> {React.string("Default")} </label>
    <input type_="text" name="language" onChange={onChange("language")} />
    <a href="" id="download"> {React.string("Export")} </a>
  </form>;
};