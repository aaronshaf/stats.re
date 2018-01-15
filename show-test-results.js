import { html, render } from 'lit-html'
import tests1 from './src/StatsTests.bs.js'
import tests2 from './src/ListStatsTests.bs.js'
import tests3 from './src/ArrayStatsTests.bs.js'

render(
  renderResults([
    ...Object.values(tests1),
    ...Object.values(tests2),
    ...Object.values(tests3)
  ]),
  document.getElementById('results')
)

function renderExplanation(expectation, result) {
  return html`${JSON.stringify(expectation)} != ${JSON.stringify(result)}`
}

function renderResult(description, didPass, expectation, result) {
  const _class = didPass ? 'success' : 'danger'
  const statusLabel = didPass
    ? 'Passed'
    : renderExplanation(expectation, result)
  return html`
  <tr class="table-${_class}">
    <th scope="row" style="width: 300px;">${description}</th>
    <td>${statusLabel}</td>
  </tr>`
}

function renderResults(results) {
  return html`${results.map(result => renderResult(...result))}`
}
