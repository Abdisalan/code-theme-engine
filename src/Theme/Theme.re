type theme = {
  background: string, //language
  language: string,
  comment: string,
  punctuation: string,
  tag: string,
  function_: string,
  functionName: string,
  property: string,
  keyword: string,
  string,
  operator: string,
  inserted: string,
};

let default = {
  background: "#2d2d2d",
  language: "#ccc",
  comment: "#999",
  punctuation: "#ccc",
  tag: "#e27771",
  function_: "#f08d49",
  functionName: "#6196cc",
  property: "#f8c555",
  keyword: "#cc99cd",
  string: "#7ec699",
  operator: "#67cdcc",
  inserted: "green",
};

let updateTheme = (_type: string, _val: string, t: theme): theme => {
  switch (_type) {
  | "background" => {...t, background: _val}
  | "language" => {...t, language: _val}
  | "comment" => {...t, comment: _val}
  | "punctuation" => {...t, punctuation: _val}
  | "tag" => {...t, tag: _val}
  | "function" => {...t, function_: _val}
  | "functionName" => {...t, functionName: _val}
  | "property" => {...t, property: _val}
  | "keyword" => {...t, keyword: _val}
  | "string" => {...t, string: _val}
  | "operator" => {...t, operator: _val}
  | "inserted" => {...t, inserted: _val}
  | _ => default
  };
};

let createTheme = (t: theme) => {
  let background = t.background;
  let language = t.language;
  let comment = t.comment;
  let punctuation = t.punctuation;
  let tag = t.tag;
  let function_ = t.function_;
  let functionName = t.functionName;
  let property = t.property;
  let keyword = t.keyword;
  let string = t.string;
  let operator = t.operator;
  let inserted = t.inserted;
  {j|
  /**
   * prism.js tomorrow night eighties for JavaScript, CoffeeScript, CSS and HTML
   * Based on https://github.com/chriskempson/tomorrow-theme
   * @author Rose Pritchard
   */

  code[class*="language-"],
  pre[class*="language-"] {
    color: $language;
    background: none;
    font-family: Consolas, Monaco, 'Andale Mono', 'Ubuntu Mono', monospace;
    font-size: 1em;
    text-align: left;
    white-space: pre;
    word-spacing: normal;
    word-break: normal;
    word-wrap: normal;
    line-height: 1.5;

    -moz-tab-size: 4;
    -o-tab-size: 4;
    tab-size: 4;

    -webkit-hyphens: none;
    -moz-hyphens: none;
    -ms-hyphens: none;
    hyphens: none;

  }

  /* Code blocks */
  pre[class*="language-"] {
    padding: 1em;
    margin: .5em 0;
    overflow: auto;
  }

  :not(pre) > code[class*="language-"],
  pre[class*="language-"] {
    background: $background;
  }

  /* Inline code */
  :not(pre) > code[class*="language-"] {
    padding: .1em;
    border-radius: .3em;
    white-space: normal;
  }

  .token.comment,
  .token.block-comment,
  .token.prolog,
  .token.doctype,
  .token.cdata {
    color: $comment;
  }

  .token.punctuation {
    color: $punctuation;
  }

  .token.tag,
  .token.attr-name,
  .token.namespace,
  .token.deleted {
    color: $tag;
  }

  .token.function-name {
    color: $functionName;
  }

  .token.boolean,
  .token.number,
  .token.function {
    color: $function_;
  }

  .token.property,
  .token.class-name,
  .token.constant,
  .token.symbol {
    color: $property;
  }

  .token.selector,
  .token.important,
  .token.atrule,
  .token.keyword,
  .token.builtin {
    color: $keyword;
  }

  .token.string,
  .token.char,
  .token.attr-_value,
  .token.regex,
  .token.variable {
    color: $string;
  }

  .token.operator,
  .token.entity,
  .token.url {
    color: $operator;
  }

  .token.important,
  .token.bold {
    font-weight: bold;
  }
  .token.italic {
    font-style: italic;
  }

  .token.entity {
    cursor: help;
  }

  .token.inserted {
    color: $inserted;
  }
|j};
};