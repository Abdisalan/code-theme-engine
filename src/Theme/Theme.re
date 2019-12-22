let createTheme = (t: ThemeTemplate.theme) => {
  let background = t.background;
  let comment = t.comment;
  let punctuation = t.punctuation;
  let tag = t.tag;
  let functionName = t.functionName;
  let boolean = t.boolean;
  let property = t.property;
  let selector = t.selector;
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
    color: #ccc;
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
    color: $boolean;
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
    color: $selector;
  }

  .token.string,
  .token.char,
  .token.attr-value,
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